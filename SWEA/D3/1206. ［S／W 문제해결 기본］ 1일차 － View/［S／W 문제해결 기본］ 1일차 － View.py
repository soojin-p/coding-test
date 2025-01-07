def count_viewable_units(buildings):
    viewable_units = 0
    
    # 맨 왼쪽 두 칸과 맨 오른쪽 두 칸은 제외하고 처리
    for i in range(2, len(buildings) - 2):
        # 현재 건물 높이
        current_height = buildings[i]
        
        # 양옆 두 칸의 최대 높이
        max_neighbor_height = max(buildings[i-2], buildings[i-1], buildings[i+1], buildings[i+2])
        
        # 조망권이 확보된 세대 수 계산
        if current_height > max_neighbor_height:
            viewable_units += current_height - max_neighbor_height
    
    return viewable_units

# 테스트 케이스 처리
for t in range(1, 11):
    # 입력 받기
    n = int(input())  # 건물 개수
    buildings = list(map(int, input().split()))
    
    # 결과 계산
    result = count_viewable_units(buildings)
    
    # 결과 출력
    print(f"#{t} {result}")
