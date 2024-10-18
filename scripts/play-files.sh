#!/bin/bash

FILES="../recordings/*"
for file in $FILES; do 
    if [ -f "$file" ]; then 
        name=$(basename "$file")
        echo "----------------------------------------------------------------------------------"
        echo "Playing file $name"
        echo "----------------------------------------------------------------------------------"
        export RECORDING_FILE=$name
        pwd
        docker compose -f ../ci-compose.yml up --abort-on-container-exit
        short="${name%%-selection*}"
        sudo mv ../artifacts/csv/data.csv ../artifacts/csv/$short.csv
        sudo mv ../artifacts/csv/previous_commit/data.csv ../artifacts/csv/previous_commit/$short.csv
    fi 
done
