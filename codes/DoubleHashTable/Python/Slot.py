from enum import Enum

class SlotStatus(Enum):
    EMPTY = 0
    DELETED = 1
    INUSE = 2

class Slot:
    MAX_TBL = 100

    def __init__(self):
        self.key = None
        self.value = None
        self.status = None
