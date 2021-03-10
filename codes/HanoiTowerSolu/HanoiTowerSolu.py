def HanoiTowerMove(num, fromm, by, to):
    if num == 1:
        print("원반1을 "+str(fromm)+"에서 "+str(to)+"로 이동")
    else:
        HanoiTowerMove(num-1, fromm, to, by)
        print("원반"+str(num)+"을(를) "+str(fromm)+"에서 "+str(to)+"로 이동")
        HanoiTowerMove(num-1, by, fromm, to)

HanoiTowerMove(3, 'A', 'B', 'C')