# DEV_DOC — Inception Developer Documentation

## Setting Up From Scratch

### 1. VM Requirements
- VirtualBox with Debian Bullseye (or Bookworm)
- At least 2 CPU cores, 2 GB RAM, 20 GB disk
- Network adapter set to NAT (or Bridged)

### 2. Install Docker on Debian
```bash
sudo apt update && sudo apt install -y docker.io docker-compose make
sudo usermod -aG docker $USER
# Log out and back in for group change to take effect
```

### 3. Clone the Repository
```bash
git clone <your-repo-url>
cd inception
```

### 4. Configure Secrets
Edit each file in `secrets/` with strong passwords:
```bash
echo "YourStrongDBPassword!" > secrets/db_password.txt
echo "YourStrongRootPassword!" > secrets/db_root_password.txt
echo "YourStrongAdminPassword!" > secrets/credentials.txt
```

### 5. Configure Environment
Copy `srcs/.env.example` to `srcs/.env` and fill in your 42 login and values:
```bash
cp srcs/.env.example srcs/.env
nano srcs/.env
```

Also update the `server_name` in `srcs/requirements/nginx/conf/nginx.conf`.

### 6. Build and Launch
```bash
make
```

This runs `make setup` (creates data dirs + /etc/hosts entry) then `make up` (builds + starts).

## Project Structure

```
inception/
├── Makefile                          # Entry point
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
├── secrets/                          # Passwords (gitignored)
│   ├── credentials.txt               # WP admin password
│   ├── db_password.txt               # MariaDB user password
│   └── db_root_password.txt          # MariaDB root password
└── srcs/
    ├── .env                          # Non-sensitive config
    ├── docker-compose.yml            # Orchestration
    └── requirements/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/nginx.conf       # TLSv1.2/1.3, fastcgi to WP
        │   └── tools/
        ├── wordpress/
        │   ├── Dockerfile
        │   ├── conf/www.conf         # PHP-FPM pool config
        │   └── tools/setup.sh        # WP download + install via WP-CLI
        └── mariadb/
            ├── Dockerfile
            ├── conf/my.cnf           # bind-address=0.0.0.0
            └── tools/setup.sh        # DB + user creation
```

## Key Docker Commands

```bash
# Build images without starting
docker compose -f srcs/docker-compose.yml build

# Start in foreground (see all logs)
docker compose -f srcs/docker-compose.yml up --build

# Execute a shell inside a running container
docker exec -it mariadb bash
docker exec -it wordpress bash
docker exec -it nginx bash

# Check MariaDB from inside container
docker exec -it mariadb mysql -u root -p

# View volume contents
ls /home/oleka/data/wordpress
ls /home/oleka/data/mariadb

# Remove everything including volumes
docker compose -f srcs/docker-compose.yml down -v
docker system prune -af
```

## Data Persistence

Data is stored on the host VM at:

| Volume | Host Path | Container Path |
|---|---|---|
| WordPress files | `/home/<login>/data/wordpress` | `/var/www/html` |
| MariaDB database | `/home/<login>/data/mariadb` | `/var/lib/mysql` |

These paths survive container restarts and rebuilds (`make down` + `make up`). Only `make clean` removes them.

## How Secrets Work

Docker secrets are mounted as files at `/run/secrets/<secret_name>` inside the container. Scripts read them with:
```bash
MY_PASSWORD=$(cat /run/secrets/db_password)
```

This prevents passwords from appearing in environment variables, `docker inspect`, or image layers.

## Networking

All containers join the `inception` bridge network. They communicate by container name (Docker's internal DNS):
- WordPress connects to MariaDB at `mariadb:3306`
- NGINX sends PHP requests to WordPress at `wordpress:9000`
- Only NGINX exposes a port to the host: `443:443`

## Common Issues

| Problem | Fix |
|---|---|
| WordPress "Error establishing DB connection" | MariaDB not ready yet — check `docker logs mariadb` |
| Port 443 already in use | `sudo lsof -i :443` and kill the process |
| Permission denied on data dir | `sudo chown -R $USER:$USER /home/<login>/data` |
| Browser certificate error | Expected — self-signed cert, click "proceed anyway" |
| Container keeps restarting | Check logs: `docker logs <container_name>` |
