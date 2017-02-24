#!/bin/sh

doctrabin="../doctra"
# Build the header documentation first
# because they are placed on top of the
# page.
for file in ../src/*.h
do
	echo "Building header documentation for $file"
	fname=$(basename "$file" ".h")
	$doctrabin "$file" "$fname.md"
done

for file in ../src/*/*.h
do
	echo "Building header documentation for $file"
	fname=$(basename "$file" ".h")
	$doctrabin "$file" "$fname.md"
done

# Build the source documentation after
# the headers because they are placed
# under them.
for file in ../src/*.c
do
	echo "Appending source documentation for $file"
	fname=$(basename "$file" ".c")
	$doctrabin "$file" "tmp.md"
	echo "\n" >> "$fname.md"
	cat "tmp.md" >> "$fname.md"
done

for file in ../src/*/*.c
do
	echo "Appending source documentation for $file"
	fname=$(basename "$file" ".c")
	$doctrabin "$file" "tmp.md"
	echo "\n" >> "$fname.md"
	cat "tmp.md" >> "$fname.md"
done

rm "tmp.md"
