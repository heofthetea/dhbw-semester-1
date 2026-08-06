---
aliases:
  - Sum Type
  - Tagged Union
---
> The [[Coproduct]] of two types -> a type consisting of multiple sub-types, where it can only be one at a time.

[[Rust]], [[Java Enum]], [[Coproduct]]

```rust
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
}
```

## tagged enum
- use an enum of [[Type|Types]]

```rust
enum Message { 
	Quit, 
	Move { x: i32, y: i32 }, 
	Write(String), 
	ChangeColor(u8, u8, u8), 
}

let msg = Message::Move(x: 42, y: 69)
```

> [!hint] Can be unwrapped using [[Rust Pattern Matching]]

