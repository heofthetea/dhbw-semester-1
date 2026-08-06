> yk the frustrating thing with quarkus/maven

### Prerequisites
- `JAVA_HOME` set to a matching java version

### Fix
- ensure the java installation actually is a JDK, and not a [[JRE]].

#### Verify installed java packages:
```bash
apt list --installed | grep openjdk
```

- if all say `-jre`, install something else like:

```bash
sudo apt install openjdk-21-jdk 
```