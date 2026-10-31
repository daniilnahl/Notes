#rewriting the sieve prime algo as a generator function
def primes_below(bound):
    candidates = list(range(2,bound))
    while(len(candidates) > 0):
        yield candidates[0]
        candidates = [c for c in candidates if c % candidates[0] != 0]
        
print([prime for prime in primes_below(100)])

# In this activity, you’ll use a Monte Carlo method to find an approximate value for π. Here’s how it
# works: two random numbers, (x,y), somewhere between (0,0) and (1,1), represent a random
# point in a square positioned at (0,0) with sides whose length are 1:
# Using Pythagoras’ Theorem, if the value of $$\sqrt{x^2 + y^2}$$ is less than 1, then the point
# is also in the top-right corner of a circle centered at (0,0) with a radius of -1:
    # Generate lots of points, count how many are within the circle segment, and divide the number of points
    # within the circle by the total number of points generated. This gives you an approximation of the area
    # of the circle segment, which should be π/4. Multiply the result by 4, and you have an approximate
    # value of π. Data scientists often use this technique to find the area under more complex curves that
    # represent probability distributions.
    
import math
import random

def approximate_pi():
    total_points = 0 # Counter for total number of points (dots)
    within_circle = 0 # Counter for points that fall inside the circle
    
    for i in range (10001):
        x = random.random()
        y = random.random()
        total_points += 1# Increase the count of total points
        
        distance = math.sqrt(x**2+y**2)# Calculate the distance of the point from the origin (0, 0)
        # Check if the point is inside the circle (distance < 1 means it's inside)
        if distance < 1:
            within_circle += 1
        # Every 1,000 points, calculate an estimate for Pi
        if total_points % 1000 == 0:
            # Pi estimate is based on the ratio of points in the circle to total points
            pi_estimate = 4 * within_circle / total_points
            # If we've reached 10,000 points, return the final estimate
            if total_points == 10000:
                return pi_estimate
            else:
                # Otherwise, yield (give) the estimate to store in a list
                yield pi_estimate
                
# Create a list of Pi estimates from the function above
estimates = [estimate for estimate in approximate_pi()]
# Calculate how far each estimate is from the real value of Pi
errors = [estimate - math.pi for estimate in estimates]

print(estimates)
print(errors)