/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** header for pipeto
*/

#ifndef PIPETO_H_
    #define PIPETO_H_
    #include <stdbool.h>
    #define UNUSED __attribute__((unused))

extern bool IS_ADMIN;

int my_console(void);

typedef struct {
    bool is_admin;
} pipeto_ctx_t;

void init_reactor(pipeto_ctx_t *ctx);
void check_reactor_status(pipeto_ctx_t *ctx);
void activate_emergency_protocols(pipeto_ctx_t *ctx);
void simulate_meltdown(pipeto_ctx_t *ctx);
void check_cooling_pressure(pipeto_ctx_t *ctx);
void send_status_report(pipeto_ctx_t *ctx);
void monitor_radiation_levels(pipeto_ctx_t *ctx);
void set_reactor_power(pipeto_ctx_t *ctx);
void run_diagnostic(pipeto_ctx_t *ctx);
void enable_remote_access(pipeto_ctx_t *ctx);
void quit(pipeto_ctx_t *ctx);
void help(pipeto_ctx_t *ctx);
void load_fuel_rods(pipeto_ctx_t *ctx);
void log_system_event(pipeto_ctx_t *ctx);
void unlock_secret_mode(pipeto_ctx_t *ctx);
void load_config(pipeto_ctx_t *ctx);
void show_history(pipeto_ctx_t *ctx);
void configure_cooling_system(pipeto_ctx_t *ctx);
void trigger_emergency_shutdown(pipeto_ctx_t *ctx);

enum commands {
    INIT_REACTOR,
    CHECK_REACTOR_STATUS,
    ACTIVATE_EMERGENCY_PROTOCOLS,
    SIMULATE_MELTDOWN,
    CHECK_COOLING_PRESSURE,
    SEND_STATUS_REPORT,
    MONITOR_RADIATION_LEVELS,
    SET_REACTOR_POWER,
    RUN_DIAGNOSTIC,
    ENABLE_REMOTE_ACCESS,
    QUIT,
    HELP,
    LOAD_FUEL_RODS,
    LOG_SYSTEM_EVENT,
    UNLOCK_SECRET_MODE,
    LOAD_CONFIG,
    HISTORY,
    CONFIGURE_COOLING_SYSTEM,
    TRIGGER_EMERGENCY_SHUTDOWN,
    COMMAND_COUNT,
};
extern const char *command_strings[];

enum commands_lib {
    INIT_STEAM_TURBINE,
    READ_TURBINE_CONFIG,
    TURINE_REMOTE_ACCESS,
    RUN_TURBINE,
    TURBINE_TEMPERATURE,
    COMMAND_COUNT_LIB
};

typedef void(*myfunc_t)(pipeto_ctx_t *ctx);
#endif /* !PIPETO_H_ */
