##
## Makefile for pipeto in /home/pepito
##
## Made by Joffrey Z.
## Login	<alexandre1.renaud@epitech.eu>
##
## Started on	Mon	Apr	2	11:57:00	2013	Théo Pierre
## Last update	Mon	Apr	2	11:58:42	2012	Théodore Poche
##

B_SRC	=	src/commands/activate_emergency_protocols.c	\
			src/commands/check_cooling_pressure.c	\
			src/commands/check_reactor_status.c	\
			src/commands/configure_cooling_system.c	\
			src/commands/enable_remote_access.c	\
			src/commands/help.c	\
			src/commands/init_reactor.c	\
			src/commands/load_fuel_rods.c	\
			src/commands/log_system_events.c	\
			src/commands/monitor_radiation_levels.c \
			src/commands/run_diagnostic.c	\
			src/commands/send_status_report.c	\
			src/commands/set_reactor_power.c	\
			src/commands/simulate_meltdown.c	\
			src/commands/quit.c	\
			src/commands/unlock_secret_mode.c	\
			src/commands/load_config.c	\
			src/commands/history.c 	\
			src/commands/trigger_emergency_shutdown.c	\

G_SRC	=	src/main.c	\
		src/my_console.c \
			src/utils.c

B_OBJ = $(B_SRC:.c=.o)

G_OBJ = $(G_SRC:.c=.o)

OBJ	= $(B_OBJ) $(G_OBJ)

NAME =	pipeto

CC ?= AFL_USE_ASAN=1 afl-gcc-fast

LDLIBS =  -ldl

CFLAGS += -Wall -Wextra -fPIC -fno-stack-protector
CFLAGS += -Wno-implicit-function-declaration -fno-pie

CPPFLAGS += -iquote ./include

all: $(NAME)

$(B_OBJ): CFLAGS +=

$(G_OBJ): CFLAGS += -g3 -ggdb

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) -lcrypto -lssl -s -no-pie

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
