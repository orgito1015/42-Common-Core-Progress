*This activity has been created as part of the 42 curriculum by oleka.*

# Inception

## Description

Inception is a system administration exercise from the 42 curriculum. The goal is to deploy a small but complete web infrastructure using **Docker Compose** inside a Virtual Machine. Each service runs in its own container, built from scratch using custom Dockerfiles based on Debian Bullseye.

The stack consists of:
- **NGINX** — the sole entry point, serving HTTPS on port 443 (TLSv1.2/1.3)
- **WordPress + PHP-FPM** — the application layer
- **MariaDB** — the database

## Instructions

### Prerequisites
- VirtualBox with Debian installed
- Docker and Docker Compose installed on the VM
- `sudo` privileges

### Install Docker on Debian
```bash
sudo apt update && sudo apt install -y docker.io docker-compose
sudo usermod -aG docker $USER   # then log out and back in
```

### Configure the project
1. Clone this repository into your VM
2. Copy `srcs/.env.example` to `srcs/.env` and fill in your actual 42 login and values
3. Edit `srcs/requirements/nginx/conf/nginx.conf` — update `server_name` with your login
4. Edit secrets in `secrets/` with strong passwords of your choice
5. Run:
```bash
make
```

The `make` command will:
- Create data directories at `/home/<login>/data/`
- Add your domain to `/etc/hosts`
- Build all Docker images
- Start all containers

### Access the site
- Website: `https://oleka.42.fr`
- WordPress admin: `https://oleka.42.fr/wp-admin`

### Useful commands
```bash
make logs    # Follow container logs
make ps      # Check container status
make down    # Stop and remove containers
make clean   # Full cleanup (removes data too)
make re      # Full rebuild
```

## Project Description

### Architecture & Design Choices

Each service (NGINX, WordPress, MariaDB) has its own dedicated container and custom Dockerfile. Containers communicate over a private Docker bridge network. Only NGINX is exposed to the outside, on port 443, using a self-signed TLS certificate.

Data is persisted using Docker named volumes with bind mounts to `/home/<login>/data/`.

### Virtual Machines vs Docker

| Virtual Machine | Docker Container |
|---|---|
| Full OS per instance | Shares the host kernel |
| GBs of disk space | MBs per image |
| Minutes to start | Seconds to start |
| Strong isolation (hypervisor) | Process-level isolation |
| Better for full OS testing | Better for service deployment |

### Secrets vs Environment Variables

| Docker Secrets | Environment Variables |
|---|---|
| Stored in `/run/secrets/` (in-memory) | Visible in `docker inspect` |
| Not exposed in image layers | Can leak in logs or history |
| Ideal for passwords, API keys | Fine for non-sensitive config |
| Only available to specified services | Available to all processes |

In this project: passwords use **secrets**, general config (DB name, domain) uses **.env**.

### Docker Network vs Host Network

| Docker Network (bridge) | Host Network |
|---|---|
| Containers have isolated IPs | Container shares host's network stack |
| DNS by container name | No container DNS |
| Controlled port exposure | All ports exposed immediately |
| **Required by this project** | **Forbidden by this project** |

### Docker Volumes vs Bind Mounts

| Docker Volume | Bind Mount |
|---|---|
| Managed by Docker | Uses an explicit host path |
| Portable across hosts | Host-path dependent |
| Better for production | Great for dev/debugging |

This project uses **named volumes with bind mounts** (hybrid), giving both persistence at a known path and proper Docker volume management.

## Resources

- [Docker official documentation](https://docs.docker.com/)
- [NGINX documentation](https://nginx.org/en/docs/)
- [WordPress CLI](https://wp-cli.org/)
- [MariaDB documentation](https://mariadb.com/kb/en/)
- [PHP-FPM documentation](https://www.php.net/manual/en/install.fpm.php)
- [Docker Compose reference](https://docs.docker.com/compose/compose-file/)
- [PID 1 and Docker best practices](https://blog.phusion.nl/2015/01/20/docker-and-the-pid-1-zombie-reaping-problem/)
- [Docker secrets documentation](https://docs.docker.com/engine/swarm/secrets/)

### AI Usage
AI (Claude) was used to: accelerate boilerplate generation for Dockerfiles and shell scripts, explain concepts like PID 1 behavior and TLS configuration, and review configuration syntax. All generated content was reviewed, tested, and understood before use.
