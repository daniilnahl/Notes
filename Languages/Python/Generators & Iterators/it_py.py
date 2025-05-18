#example of simplest iterator
# You’ve designed an
# Interrogator class that programmers can ask to iterate over its questions, without having to tell
# the programmer anything about how Interrogator stores its questions
class Interrogator:
    def __init__(self, questions):
        self.questions = questions
        
    def __iter__(self):
        return self.questions.__iter__()
    
questions = ["What is your name?", "What is your quest?","What is the average airspeed velocity of an unladen swallow?"]
awkward_person = Interrogator(questions)
for question in awkward_person:
    print(question)
    
#CUSTOM ITERATOR
# classical-era algorithm called the Sieve of Eratosthenes. To find
# prime numbers between 2 and an upper bound value, n, first, you must list all of the numbers in
# that range. Now, 2 is a prime, so return that. Then, remove 2 from the list, and all multiples of 2, and
# return the new lowest number (which will be 3). Continue until there are no more numbers left in
# the collection. Every number that gets returned using this method is a successively higher prime. It
# works because any number you find in the collection to return did not get removed at an earlier step,
# so it has no lower prime factors other than itself.
class PrimesBelow:
    def __init__(self, bound):
        self.candidate_numbers = list(range(2,bound))
        
    def __iter__(self):
        return self
    
    def __next__(self): #defines next and the exit condition: condition. If there are no remaining numbers in the collection, then the iteration can stop.
        if len(self.candidate_numbers) == 0:
            raise StopIteration
        #Complete the implementation of __next__() by selecting the lowest number in the collection
        # as the value for next_prime and removing any multiples of that number before returning
        # the new prime
        next_prime = self.candidate_numbers[0]
        self.candidate_numbers = [x for x in self.candidate_numbers if x % next_prime != 0]
        return next_prime
    
primes_to_a_hundred = [prime for prime in PrimesBelow(100)]
print(primes_to_a_hundred)