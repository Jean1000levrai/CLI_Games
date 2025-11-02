#!/bin/bash

#!/bin/bash

git add .

if git diff --cached --quiet; then
    echo "No changes to commit."
else
    git commit
    git push origin main
fi
