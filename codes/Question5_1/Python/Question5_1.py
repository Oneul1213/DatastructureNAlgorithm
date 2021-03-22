import StaffModule as sm
import CircularLinkedListModule as clm

def WhoIsOnDutyNext(clist, name, days_later):
    data = clist.LFirst()
    if data[0] is True:
        if data[1].name is name:
            for i in range(days_later):
                data = clist.LNext()
            return data[1]
    
    while True:
        data = clist.LNext()
        if data[1].name is name:
            for i in range(days_later):
                data = clist.LNext()
            return data[1]

clist = clm.CircularLinkedList()

# 4명의 사원 정보 저장
clist.LInsert(sm.Staff(2201036, "정바름"))
clist.LInsert(sm.Staff(2003014, "나유연"))
clist.LInsert(sm.Staff(1903048, "구아름"))
clist.LInsert(sm.Staff(2003075, "신재현"))

# 누구 당직인지 확인
WhoIsOnDutyNext(clist, "정바름", 6).ShowStaffInfo()
