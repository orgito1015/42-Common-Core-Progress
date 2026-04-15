LOGIN		= oleka
DATA_DIR	= /home/$(LOGIN)/data

all: setup up

setup: secrets
	@mkdir -p $(DATA_DIR)/wordpress $(DATA_DIR)/mariadb
	@grep -q "$(LOGIN).42.fr" /etc/hosts || \
		echo "127.0.0.1 $(LOGIN).42.fr" | sudo tee -a /etc/hosts

secrets:
	@for f in secrets/*.txt.example; do \
		target=$$(echo $$f | sed 's/.example//'); \
		if [ ! -f "$$target" ]; then \
			cp "$$f" "$$target"; \
			echo "Created $$target from $$f — edit it with real values then run: make up"; \
		fi; \
	done

up:
	docker compose -f srcs/docker-compose.yml up -d --build

down:
	docker compose -f srcs/docker-compose.yml down

stop:
	docker compose -f srcs/docker-compose.yml stop

start:
	docker compose -f srcs/docker-compose.yml start

clean: down
	docker system prune -af
	sudo rm -rf $(DATA_DIR)

re: clean all

logs:
	docker compose -f srcs/docker-compose.yml logs -f

ps:
	docker compose -f srcs/docker-compose.yml ps

.PHONY: all setup secrets up down stop start clean re logs ps
