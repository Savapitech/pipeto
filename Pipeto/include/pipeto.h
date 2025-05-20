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

void init_reactor(void);
void check_reactor_status(void);
void activate_emergency_protocols(void);
void simulate_meltdown(void);
void check_cooling_pressure(void);
void send_status_report(void);
void monitor_radiation_levels(void);
void set_reactor_power(void);
void run_diagnostic(void);
void enable_remote_access(void);
void quit(void);
void help(void);
void load_fuel_rods(void);
void log_system_event(void);
void unlock_secret_mode(void);
void load_config(void);
void show_history(void);
void configure_cooling_system(void);
void trigger_emergency_shutdown(void);

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

#endif /* !PIPETO_H_ */
