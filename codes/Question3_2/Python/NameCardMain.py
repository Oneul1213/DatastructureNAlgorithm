import ArrayListModule as alm
import NameCardModule as ncm

arlist = alm.ArrayList()

# 3명의 정보 저장
arlist.LInsert(ncm.NameCard("바름", "010-1234-5678"))
arlist.LInsert(ncm.NameCard("유연", "010-9123-4567"))
arlist.LInsert(ncm.NameCard("재현", "010-8912-3456"))

# 특정 한 명의 이름 탐색 및 정보 출력
data = arlist.LFirst()
if data[0] is True:
    if data[1].NameCompare("바름") is True:
        data[1].ShowNameCardInfo()
    
    data = arlist.LNext()
    while data[0] is True:
        if data[1].NameCompare("바름") is True:
            data[1].ShowNameCardInfo()
        data = arlist.LNext()
print()

# 특정 한 명의 이름 탐색 및 전화번호 변경
data = arlist.LFirst()
if data[0] is True:
    if data[1].NameCompare("유연") is True:
        data[1].ChangePhoneNum("010-7891-2345")
    
    data = arlist.LNext()
    while data[0] is True:
        if data[1].NameCompare("유연") is True:
            data[1].ChangePhoneNum("010-7891-2345")
        data = arlist.LNext()

# 특정 한 명의 이름 탐색 및 삭제
data = arlist.LFirst()
if data[0] is True:
    if data[1].NameCompare("재현") is True:
        arlist.LRemove()
    
    data = arlist.LNext()
    while data[0] is True:
        if data[1].NameCompare("재현") is True:
            arlist.LRemove()
        data = arlist.LNext()

# 남아있는 데이터 출력
data = arlist.LFirst()
if data[0] is True:
    data[1].ShowNameCardInfo()
    
    data = arlist.LNext()
    while data[0] is True:
        data[1].ShowNameCardInfo()
        data = arlist.LNext()
print()
