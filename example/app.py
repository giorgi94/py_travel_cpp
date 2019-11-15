from pytravel import travel

items = travel("/home/gio/Pictures/wallpaper")


for item in items[:5]:
    print(item)
