#!/bin/bash
# Script to rename all .cpp files in child directories to lowercase
# Developer: Ronald Baker

echo "Converting all .cpp files in child directories to lowercase..."

# Find all .cpp files in the current directory and its subdirectories
find . -type f -name "*.cpp" | while read -r file; do
    # Get the directory and filename separately
    dir=$(dirname "$file")
    base=$(basename "$file")

    # Convert the filename to lowercase
    lowercase_name=$(echo "$base" | tr '[:upper:]' '[:lower:]')

    # Rename the file if the name has changed
    if [ "$base" != "$lowercase_name" ]; then
        mv "$file" "$dir/$lowercase_name"
        echo "Renamed: $file -> $dir/$lowercase_name"
    fi
done

echo "Conversion of .cpp files to lowercase complete."

