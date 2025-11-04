#!/bin/bash

git add .

if git diff --cached --quiet; then
    echo "No changes to commit."
else
    git commit

    git push origin main
    if [ $? -ne 0 ]; then
        git pull --rebase origin main
        git push origin main
    fi
fi
