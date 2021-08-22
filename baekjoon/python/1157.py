data = list(input().upper())
cnt = 0
for i in range(len(data)):
    if data.count(data[i])>cnt:
        cnt = data.count(data[i])
        result = data[i]
    elif data.count(data[i])==cnt:
        candidate = data[i]
if(candidate == result):
    print("?")
else:
    print(result)