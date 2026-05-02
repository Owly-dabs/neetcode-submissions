from math import ceil
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # Brute force method O(n^2): 
        # Iterate over each period of time
        # Check if any positions are the same
        # Within a fleet, determine the new speed, aka the lowest speed

        # Efficient way to check for same positions O(n)
        # Hash map with keys as positions and values as the speed of cars

        # Even more efficient way:
        # If a car with a lower position reaches the destination
        # in a time equals or lower than a car with a higher position,
        # they must have formed a fleet. 

        cars = zip(position, speed)
        cars = sorted(cars, key=lambda x:x[0], reverse=True)

        slowest_time = 0
        fleets = 0
        for c in cars:
            # get time
            time = (target-c[0])/c[1]
            # if time is greater than slowest time
            if time > slowest_time:
                fleets += 1
                slowest_time = time
            # new slowest time and add 1 to fleets
            # if time is smaller or equal to slowest time
            # continue

        return fleets