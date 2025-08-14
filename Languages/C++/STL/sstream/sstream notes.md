# What is sstream?
<sstream> is a C++ standard library header that provides string-based stream classes—istringstream, ostringstream, and stringstream—which enable formatted input/output operations on strings instead of files or the console.

# How does sstream work?
It defines stream classes that wrap a stringbuf object as their underlying storage. These classes inherit from standard stream base classes (istream, ostream, or both via iostream), allowing use of the familiar >> and << operators for reading from or writing to strings. The internal buffer can be initialized from a std::string or modified dynamically using member functions like str() and clear().

# Why does it work?
It works because C++’s stream architecture is built on the separation of formatting/parsing logic (stream classes) and data storage (stream buffers). <sstream> leverages this by pairing the standard stream interface with a stringbuf—a buffer that stores its data in memory as a std::string. This lets you reuse the full power of the iostream formatting/parsing system without dealing with manual string parsing or concatenation logic.