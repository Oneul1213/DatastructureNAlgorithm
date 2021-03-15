class NameCard:
    def __init__(self, name, phone):
        self.name = name
        self.phone = phone
    
    def ShowNameCardInfo(self):
        print("이름 : {}".format(self.name))
        print("번호 : {}".format(self.phone))

    def NameCompare(self, name):
        return self.name == name
    
    def ChangePhoneNum(self, phone):
        self.phone = phone
