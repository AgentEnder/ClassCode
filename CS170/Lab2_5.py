timeFlash = 0
soundThunder = 0
run = 0
    
    
while True:
    if (run == 0):
        soundThunder = input("Time elapsed before thunder. In seconds:")
        if(soundThunder.lower() == "exit"):
            break
        soundThunder = float(soundThunder)
        dLight = 1100 * soundThunder / 5280
        print (dLight , "Miles away")
