#!/bin/bash

BINARY="./pipeto"
CONFIG_FILE="config.ini"
LOG_FILE="Data/system.log"

echo "### Testing Pipeto Security Fixes ###"

# 1. Test hardcoded password fix
strings $BINARY | grep "admin123" >/dev/null
if [ $? -eq 0 ]; then
    echo "[FAIL] Hardcoded password still accepted!"
else
    echo "[PASS] Hardcoded password rejected."
fi

# 2. Test config.ini buffer overflow fix (try to trigger segfault)
echo -e "[bad config\n" > $CONFIG_FILE
timeout 3 echo "load_config" | $BINARY 2>/dev/null >/dev/null
if [ $? -ne 0 ]; then
    echo "[FAIL] Program hangs on bad config (possible overflow)."
else
    echo "[PASS] No crash on malformed config.ini."
fi
rm -f $CONFIG_FILE

# 3. Test log injection fix
echo -n "log_system_event\n" | $BINARY >/dev/null 2>/dev/null
if grep -q "SECRET_KEY_LEAKED" $LOG_FILE; then
    echo "[FAIL] Secret leaked in logs!"
else
    echo "[PASS] No secret leak in logs."
fi

# 3. Test log injection fix
echo -n "monitor_radiation_levels\n123784562378657489w23658972346582348547482375698734869734867093182906890354 786902348790673549064723908690386-903480-890-83490678394578-034876-03480-68340-8560-34860-438-0" | $BINARY >/dev/null 2>/dev/null
if [ $? -ne 0 ]; then
    echo "[FAIL] Stack overflow in monitor_radiation_levels !"
else
    echo "[PASS] No stack overflow in monitor_radiation_levels."
fi

echo -n "check_reactor_status" | $BINARY | grep "fdc01ef46db8c1d3d46967a7d76943c1" >/dev/null
if [ $? -ne 0 ]; then
    echo "[FAIL] Bad hash still used in check_reactor_status!"
else
    echo "[PASS] Good hash used in check_reactor_status."
fi
echo "### Testing completed ###"
