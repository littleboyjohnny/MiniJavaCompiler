from pathlib import Path

header = [
    "// This is a personal academic project. Dear PVS-Studio, please check it.\n",
    "// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com\n\n",
]


def main():
    p = Path(".")

    for file in p.rglob("*.[ch]pp"):
        with open(file, "r") as f:
            lines = f.readlines()
        if header[0] not in lines:
            print(file)
            lines = header + lines
            with open(file, "w") as f:
                f.writelines(lines)


if __name__ == "__main__":
    main()
