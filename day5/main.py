import sys
from typing import List


def parse_crates(s: str) -> List[List[str]]:
    crates = []
    sl = [l for l in s.splitlines()] 
    sl.pop() # pop the line with numbers

    for line in sl:
        for i, idx in enumerate(range(1, len(line), 4)):
            if i >= len(crates):
                crates.append([])
            if line[idx] != " ":
                crates[i].append(line[idx])
    return crates


def part1(file_path: str) -> None:

    try:
        f = open(file_path);
    except Exception as e:
        print(f"[!] Error: {e}");
        return

    crates_raw, movi = f.read().split("\n\n")
    assert len(crates_raw) != 0

    crates = parse_crates(crates_raw)

    for inst in movi.splitlines():
        a = int(inst.split(" ")[1])
        b = int(inst.split(" ")[3])
        c = int(inst.split(" ")[5])
        for _ in range(a):
            crates[c - 1].insert(0, crates[b - 1].pop(0))

    print("[p1] %s: %s" % (file_path, "".join(x[0] for x in crates)))
    f.close()
    return


def part2(file_path: str) -> None:
    try:
        f = open(file_path);
    except Exception as e:
        print(f"[!] Error: {e}");
        return

    crates_raw, movi = f.read().split("\n\n")
    assert len(crates_raw) != 0

    crates = parse_crates(crates_raw)

    for inst in movi.splitlines():
        a = int(inst.split(" ")[1])
        b = int(inst.split(" ")[3])
        c = int(inst.split(" ")[5])
        for i in reversed(range(a)):
            crates[c - 1].insert(0, crates[b - 1].pop(i))

    print("[p2] %s: %s" % (file_path, "".join(i[0] for i in crates)))
    f.close()
    return


def main(argv: List[str]) -> None:
    for i in argv[1:]:
        part1(i)
        part2(i)


if __name__ == "__main__":
    main(sys.argv)
