class Person:
    def __init__(self, ssn=0, name="", address=""):
        self.ssn = ssn
        self.name = name
        self.address = address

    def ShowPerInfo(self):
        print("주민등록번호: {}".format(self.ssn))
        print("이름: {}".format(self.name))
        print("주소: {}".format(self.address))
        print()
