#!/bin/bash
pids=()

cd docs/html
python3 -m http.server 6969 & pids+=($!)
cd ../../build/examples
python3 -m http.server 6968 & pids+=($!)

trap '
    for pid in "${pids[@]}"; do
        echo "killing $pid"
        kill "$pid" 2>/dev/null || true
    done
    wait "${pids[@]}" 2>/dev/null || true
    exit 130
' INT

wait

