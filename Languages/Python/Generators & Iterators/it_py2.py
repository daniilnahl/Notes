import itertools
class Primes:
    def __init__(self):
        self.current = 2
        
    def __iter__(self):
        return self
    
    def __next__(self):
        while True:
            current = self.current
            self.current += 1  # Move to the next number on each iteration
            
            # Check if the current number is prime
            square_root = int(current ** 0.5)
            is_prime = True

            if square_root >= 2:
                for i in range(2, square_root + 1):
                    if current % i == 0:
                        is_prime = False
                        break

            # Return the current prime number
            if is_prime:
                return current
                    
#[p for p in Primes() if p < 100]
# Because the iterator never raises StopIteration, this program will never finish. You’ll
# have to force it to exit.

# this code makes it possible to find prime numbers below 100 from the infinite sequence because takewhile() is another iterator which supplies the function until it returns false at which it will raise StopIteration and stop.
print([p for p in itertools.takewhile(lambda x: x<100, Primes())]) #take while turns infinite into finite

