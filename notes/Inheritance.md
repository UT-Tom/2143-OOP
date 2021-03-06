# **Inheritance**

Property that instances of a child class (subclass, derived class) can access both data and behavior (methods) associated with a parent class (superclass).

```cpp
class SpaceObject {
private:
	int x, y;

public:
	void moveto(){
		// update coords
	}
};

class SpaceCraft : public SpaceObject {
	bool collect(){
		// main called moveTo();
		// collect asteroid
	}
};
```

### **The is-a test**

- A florist is a shopkeeper
- A double room is a hotel room
- A square is a rectangle
- A rectangle is a parallelogram
- A bird is NOT a mammal
- An apple pie is NOT an apple.

### **Inheritance is transitive**

### **Why use Inheritance**

1. REUSE CODE
1. REUSE CONCEPTS

### Multiple inheritance

C++
```cpp
class AudioBook : public AudioMaterials, public Book {

};
```

Java
```java
class AudioBook implements IAudioMaterials, IBook {

};
```

- Subclassing for specialization (subtyping)
- Subclassing for specification
- Subclassing for construction
- Subclassing for generalization
- Subclassing for extension
- Subclassing for limitation
- Subclassing for variance
- Subclassing for combination

## Inheritance Scope

***

![](class_inheritance_diagram.png)

***

**Public inheritance**

Parent's public & protected data will be accessible by child class.

**Protected inheritance**

Parent's protected data will be accessible by child class.

**Private inheritance**

Parent's private data will be accessible by child class.
