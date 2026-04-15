# USER_DOC — Inception User Documentation

## What Services Are Running?

| Service | Role | Port |
|---|---|---|
| **NGINX** | Web server / HTTPS entry point | 443 (external) |
| **WordPress** | CMS application (PHP-FPM) | 9000 (internal only) |
| **MariaDB** | Database | 3306 (internal only) |

Only port **443** is accessible from outside. All other ports are internal to the Docker network.

## Starting and Stopping

```bash
# Start everything (first time — also builds images)
make

# Start already-built containers
make start

# Stop containers (keeps data)
make stop

# Stop and remove containers (keeps data)
make down
```

## Accessing the Website

Open your browser and go to:

```
https://oleka.42.fr
```

Your browser will warn about the self-signed certificate — click "Advanced" and proceed. This is expected for a local development setup.

### WordPress Admin Panel

```
https://oleka.42.fr/wp-admin
```

Login with the admin credentials defined in your `secrets/credentials.txt`.

> ⚠️ The admin username must NOT contain "admin" or "administrator" — check your `.env` file.

## Managing Credentials

All sensitive credentials are stored in the `secrets/` directory at the repo root:

| File | Contains |
|---|---|
| `secrets/credentials.txt` | WordPress admin password |
| `secrets/db_password.txt` | MariaDB user password |
| `secrets/db_root_password.txt` | MariaDB root password |

> ⚠️ Never commit these files to git. They are in `.gitignore`.

Non-sensitive config (usernames, domain, DB name) is in `srcs/.env`.

## Checking That Services Are Running

```bash
# See all container statuses
make ps

# Follow live logs of all containers
make logs

# Check a specific container
docker logs nginx
docker logs wordpress
docker logs mariadb
```

All containers should show status **Up**. If a container is restarting repeatedly, check its logs.
