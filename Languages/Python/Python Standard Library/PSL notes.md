## WHAT IS THE STANDARD LIBRARY?
IT'S A LIBRARY with many useful modules(libraries). It comes installed with python automatically.
There are two types of modules: high level and low level.
    
USEFUL MODULES:
- pathlib: provides a route to interact with filesystem paths. 
- exists: Checks whether the path exists in the filesystem and whether it is a file or a directory.
- is_dir: Checks whether the path is a directory.
- is_file: Checks whether the path is a file.
- iterdir: Returns an iterator with path objects to all the files and directories contained within the path object.
- mkdir: Creates a directory in the path indicated by the path object.
- open: Opens a file in the current path, similar to running open and passing the string representation of the path. It returns a file object that can be operated like any other.
- read_text: Returns the content of the file as a Unicode string. If the file is in binary format, the read_bytes method should be used instead.

#### WHAT IS A HIGH LEVEL MODULE?
Focus on ease of use and readibility. Basically take control behind the scenes and let the user focus on the more abstract operations. Manages complex hardware operations automatically.

HIGH LEVEL MODULES:
- shutil: allows to recursively copy, move and delete files.
- datetime: time stuff.
- dataclasses: provides tools to create classes that store data by auto generating basic methods.
- difflib: to check differences line by line across two blocks of text.
- re: regular experssions.
- gzip, zipfile, tarfile: data compressing and archiving.
- xml, json, csv, config: for working with file formats.
- sched: to schedule events in Standard Library.
- argparse: for creating command-line interfaces.

#### WHAT IS A LOW LEVEL MODULE?
Low level modules interact more directly interact with hardware. 
Give user more control over the system, but is harder to write and understand/
Ex: Internet protocols, text formatting, testing and interacting with C code.
         
Most often used low level libraries are built on low level modules from standard library. Such as: jinja2, requests, flask, cython, and cffi.

Low level modules:
- asyncio: To write asynchronous code
- typing: To type hint
- contextvar: To save state based on the context
- contextlib: To help with the creation of context managers
- doctest: To verify code examples in documentation and docstrings
- pdb and bdb: To access debugging tools