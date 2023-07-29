"""
Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will the same.

Examples:
Input: houses = [1,2,3], heaters = [2]
Output: 1

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1

Input: houses = [1,5], heaters = [2]
Output: 3
"""

class Solution:
          1 1
        |  |  |
           2
        1  2  3

                       | 
                       5    6
        1  2  3  [4]  [5]  [6]
        |


         1    2    3  [4]  [5]

        [1]  [2]  [3]  [4]  5


        1. for any house found the min distance to the closest heater
        2. from all distances for all houses find the longest distance to a heater.

        Conclusion: For all houses find the distance to the closest heater.
    
        Suboptimal solution

        TC: O(NlogN + MlogM + M + NM + M), where N is len(heaters) and M is len(houses)
        SC: O(NlogN + MlogM + M), where N is len(heaters) and M is len(houses)
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()
        houses.sort()

        dist_per_house = dict()
        for house in houses:
            dist_per_house[house] = float('inf')

        for house in houses:
            for heater in heaters:
                dist_per_house[house] = min([abs(house - heater), dist_per_house[house]])

        dist: int = 0
        for house in dist_per_house:
            dist = max(dist, dist_per_house[house])

        return dist

#=======================================================================
mid      |
right      |
left       |
         1 2 6 9
         0 1 2 3

         left:     0
         right:    3
         mid: 
         distance:
         house:    1
    def get_from_right_distance_to_closest_heater(self, house: int, heaters: List[int]) -> int:
        left: int = 0
        right: int = len(heaters) - 1

        while left < right:
            mid: int = left + (right - left) // 2

            if house <= heaters[mid]:
                right = mid
            else:
                left = mid + 1
        
        if left == right and heaters[left] >= house:
            return heaters[left] - house
        
        return sys.maxsize * 2 + 1


    def get_from_left_distance_to_closest_heater(self, house: int, heaters: List[int]) -> int:
        left: int = 0
        right: int = len(heaters) - 1

        while left < right:
            mid: int = left + (right - left + 1) // 2

            if house >= heaters[mid]:
                left = mid
            else:
                right = mid - 1
            
        if left == right and house >= heaters[left]:
            return house - heaters[left]
        
        return sys.maxsize * 2 + 1


        |
        1 4 8 11 
    
        distance:

        TC: O(MlogM + N(logM + logM)), where N == leN(house), M == len(heaters) 
        SC: O(1)
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()

        distance: int = 0
        for house in houses:
            distance = max([distance, 
            min([self.get_from_left_distance_to_closest_heater(house, heaters), 
            self.get_from_right_distance_to_closest_heater(house, heaters)])])
        
        return distance

#=========================================================================
   def find_closest_heater(self, house: int, heaters: List[int]) -> int:
        left: int = 0
        right: int = len(heaters) - 1

        while left <= right:
            mid: int = left + (right - left) // 2

            if heaters[mid] == house:
                return mid
            elif heaters[mid] < house:
                left = mid + 1
            else:
                right = mid - 1

        if right < 0:
            return 0
        
        if left >= len(heaters):
            return len(heaters) - 1

        if abs(heaters[right] - house) < abs(heaters[left] - house):
            return right
        return left

    #  TC: O(NlogM), where N == len(houses), M == len(heaters)
    #  SC: O(MlogM), where M == len(heaters)
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()

        radius: int = 0
        for house in houses:
            idx: int = self.find_closest_heater(house, heaters)
            distance = abs(house - heaters[idx])
            radius = max(distance, radius)
        
        return radius

# ========================================================
"""
        |
        1 2 3 4

        |
        1 4

        res: 0
        i:   0

        TC: O(NlogN + MlogM + N), where N == len(heaters), M == len(houses)
        SC: O(NlogN + MlogM), where N == len(heaters), M == len(houses)
"""
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()
        houses.sort()

        res: int = 0
        i: int = 0
        for house in houses:
            while i < len(heaters) - 1 and abs(house - heaters[i]) >= abs(heaters[i + 1] - house):
                i += 1
            
            res = max(res, abs(house - heaters[i]))
        return res

class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        radiuses: List[int] = [sys.maxsize] * len(houses)
        radius_i: int = 0
        r: int = 0
        heaters_l: int = 0
        while r < len(houses) and heaters_l < len(heaters):
            if houses[r] <= heaters[heaters_l]:
                radiuses[radius_i] = heaters[heaters_l] - houses[r]
                radius_i += 1
                r += 1
            else:
                heaters_l += 1

        radius_i = len(radiuses) - 1
        r = len(houses) - 1
        heaters_l = len(heaters) - 1
        while r >= 0 and heaters_l >= 0:
            if houses[r] >= heaters[heaters_l]:
                radiuses[radius_i] = min(radiuses[radius_i], houses[r] - heaters[heaters_l])
                radius_i -= 1
                r -= 1
            else:
                heaters_l -= 1
        return max(radiuses)

class Solution:
  # TC: O(N log N + M log N), where N == len(heaters) and M == len(houses)
  # SC: O(N log N), where N == len(heaters)
  def findRadius(self, houses: List[int], heaters: List[int]) -> int:
    heaters.sort()  # O(N log N), where N == len(heaters)
    result: int = 0
    for house in houses:
      i: int = self.binarySearch(
        heaters, house)  # TC: O(log N), where N == len(heaters)
      left_distance: int = house - heaters[i - 1] if i > 0 else sys.maxsize
      right_distance: int = heaters[i] - house if i < len(
        heaters) else sys.maxsize

      result = max(result, min(left_distance, right_distance))
    return result

  # TC: O(log N), where N == len(heaters)
  # SC: O(1)
  def binarySearch(self, heaters: List[int], house: int) -> int:
    l: int = 0
    r: int = len(heaters) - 1  # TC: O(1)
    while l < r:
      m: int = l + (r - l) // 2
      if heaters[m] == house:
        return m
      elif heaters[m] > house:
        r = m
      else:
        l = m + 1
