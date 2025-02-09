# Modularity

A very important aspect of any software project is how easy is to maintain it.
New features, bug correction, those aspects has direct impact on cost and
overall quality.

In any software development methodology, separation of concerns is key to add
those qualities into the codebase.

## Why and when break the source into several files

Simplest answer is _separation of concerns_, but let's try to exemplify what
does it really means.

Supposer our program needs to store contact info into files. Some functions are
dedicated to get the data, other to validate it and finally some function do the
needed logic to store and retrieve contacts from file correctly.

From those 3 major concerns, 2 are clearly tightly coupled, data acquisition and
validation, but file handling can abstract a lot from what should be in files.
