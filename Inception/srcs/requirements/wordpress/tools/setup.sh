#!/bin/bash
set -e

DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/credentials)
WP_USER_PASSWORD=$(echo "${WP_ADMIN_PASSWORD}user" | sha256sum | cut -c1-16)

WP_PATH="/var/www/html"

if [ ! -f "${WP_PATH}/wp-config.php" ]; then

    rm -rf ${WP_PATH}/*

    wp core download --path="${WP_PATH}" --allow-root

    wp config create \
        --path="${WP_PATH}" \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${DB_PASSWORD}" \
        --dbhost="mariadb:3306" \
        --allow-root

    # Wait for MariaDB using mysqladmin ping
    until mysqladmin ping -h mariadb -u"${MYSQL_USER}" -p"${DB_PASSWORD}" --silent 2>/dev/null; do
        echo "Waiting for MariaDB..."
        sleep 2
    done

    wp core install \
        --path="${WP_PATH}" \
        --url="https://${DOMAIN_NAME}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --allow-root

    wp user create \
        "${WP_USER}" "${WP_USER_EMAIL}" \
        --role=subscriber \
        --user_pass="${WP_USER_PASSWORD}" \
        --path="${WP_PATH}" \
        --allow-root

    chown -R www-data:www-data "${WP_PATH}"
fi

exec php-fpm7.4 -F
