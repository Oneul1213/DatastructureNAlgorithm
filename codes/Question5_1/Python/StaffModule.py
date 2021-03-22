class Staff:
    def __init__(self, o_num=0, name=""):
        self.o_num = o_num
        self.name = name
    
    def ShowStaffInfo(self):
        print("사번 : {}".format(self.o_num))
        print("이름 : {}".format(self.name))
