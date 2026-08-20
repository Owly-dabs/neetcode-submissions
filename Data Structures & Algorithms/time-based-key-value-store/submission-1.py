class TimeMap:

    def __init__(self):
        self.trees = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.trees:
            self.trees[key] = TimeTree()
            self.trees[key].insert(value, timestamp)
        else:
            self.trees[key].insert(value, timestamp)
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.trees:
            return ""
        return self.trees[key].search(timestamp)

class TimeTree:

    def __init__(self):
        self.tree = []

    def insert(self, value: str, ts: int):
        self.tree.append((ts,value))
    
    def search(self, ts:int):
        left = 0
        right = len(self.tree) - 1

        while left <= right:
            mid = (left + right) // 2

            if ts == self.tree[mid][0]:
                return self.tree[mid][1]

            if ts < self.tree[mid][0]:
                right = mid - 1
                continue

            else:
                # check if the item after is larger
                if (mid + 1 < len(self.tree) and ts < self.tree[mid+1][0]) or mid == len(self.tree) - 1:
                    return self.tree[mid][1]
                left = mid + 1
                continue
        
        return ""

"""
1, 2, 4, 6, 7
get 5
4 -> 6 -> 4

1, 2, 4, 6, 7, 9, 13
"""
