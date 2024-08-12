from collections import defaultdict
import heapq
from typing import List

# S: O(n)
class FoodRatings:
    # T: O(n * log(n))
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # k: cuisine, v: max_heap[(rating, food)]
        self.cuisine_food_ratings = defaultdict(list)

        # k: food, v: cuisine
        self.food2cuisine = {}

        # k: food, v: rating
        self.food2rating = {}

        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food2cuisine[food] = cuisine
            self.food2rating[food] = rating
            heapq.heappush(self.cuisine_food_ratings[cuisine], (-rating, food))

    # T: O(log(n))
    def changeRating(self, food: str, newRating: int) -> None:
        self.food2rating[food] = newRating
        cuisine = self.food2cuisine[food]
        heapq.heappush(self.cuisine_food_ratings[cuisine], (-newRating, food))

    # T: O(n * log(n))
    def highestRated(self, cuisine: str) -> str:
        neg_rating, food = self.cuisine_food_ratings[cuisine][0]
        while self.food2rating[food] != -neg_rating:
            # In case the previous highest rating has been changed to a lower one
            heapq.heappop(self.cuisine_food_ratings[cuisine])
            neg_rating, food = self.cuisine_food_ratings[cuisine][0]
        return food

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)