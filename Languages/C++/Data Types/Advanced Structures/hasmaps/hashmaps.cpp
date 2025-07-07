#include <iostream>
#include <map>
#include <string>

int main() {
    // Create a hash map (map)
    std::map<std::string, int> ages;

    // Insert key-value pairs
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    ages["Charlie"] = 35;

    // Access values using keys
    std::cout << "Alice's age: " << ages["Alice"] << std::endl; // Output: Alice's age: 30
    std::cout << "Bob's age: " << ages["Bob"] << std::endl;   // Output: Bob's age: 25
    std::cout << "Charlie's age: " << ages["Charlie"] << std::endl; // Output: Charlie's age: 35

    // Check if a key exists
    if (ages.find("David") != ages.end()) {
        std::cout << "David's age: " << ages["David"] << std::endl;
    } else {
        std::cout << "Key 'David' not found." << std::endl; // Output: Key 'David' not found.
    }

    // Iterate through the hash map
    std::cout << "All ages:" << std::endl;
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    // Output:
    // All ages:
    // Charlie: 35
    // Bob: 25
    // Alice: 30

    // Remove a key-value pair
    ages.erase("Bob");

   // Check size of hash map
    std::cout << "Hash map size: " << ages.size() << std::endl;  // Output: Hash map size: 2

    return 0;
}


//NOTE ON KEYS THAT DONT EXIST:
//When you use the [] operator to access a key in a std::map (like s_map[s[i]] or 
//t_map[t[i]]), if that key doesn't already exist in the map, it's automatically inserted into the map, 
//and its corresponding value is default-initialized(0), which means s_map[s[i]] += 1 works even if s[i] is not already in the map.

