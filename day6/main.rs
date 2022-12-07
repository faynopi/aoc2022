use std::env;
use std::fs;

fn solve(fp: String, p: i8, n: usize) {
    let f = fs::read_to_string(fp.clone()).unwrap();

    for (ln, l) in f.lines().enumerate() {
        let ans = l
            .as_bytes()
            .windows(n)
            .position(|a| !(0..n - 1).any(|b| (b + 1..n).any(|c| a[b] == a[c])))
            .unwrap();
        println!("[p{}] {}: {}:{}", p, fp, ln + 1, (ans + n));
    }
}

fn main() {
    for i in env::args().into_iter().skip(1) {
        solve(i.clone(), 1, 4);
        solve(i.clone(), 2, 14);
    }
}
