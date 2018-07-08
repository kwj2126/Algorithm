N = int(input())
for i in range(N):
    string = input()
    string = string.split(' ')
    ans = 'god'
    for idx, name in enumerate(string):
        if idx != 0:
            ans += name
    print(ans)