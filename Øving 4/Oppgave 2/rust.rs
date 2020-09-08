use std::io;

fn main() {

    println!("Please enter your input: ");

    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .ok()
        .expect("Couldn't read line");

    
    input = input.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;");
    println!("{}", input);
}