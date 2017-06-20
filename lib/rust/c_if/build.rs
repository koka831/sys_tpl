extern crate gcc;

fn main() {
    gcc::compile_library("lib.a", &["../../c/lib.c"]);
}
