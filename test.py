if __name__ == "__main__":
    with open("./allNumbers.txt", "r") as f:
        lines = f.readlines()
        for line in lines:
          line = line.replace("\n", "")
          print(line)
