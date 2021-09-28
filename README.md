# SciTec Coding Challenge

## Build and Run Instructions
```
git clone https://github.com/mlondon28/LLAtoECF.git
cd LLAtoECF
mkdir build && cd build
cmake ..
./interpolateVelocity
```

##  Notes: 
### Versions:
- gcc 9.3.0
- cmake 3.16
- C++ 11

### Room for Improvement:
There are several places I would improve with more time.
- error handling
- unit testing
- CLI arg input


## Sample Output:

### ECF Coordinates [x,y,z] for the first 10 data points:
```
ECF X, Y, Z [meters]
X: -2964583.8851        Y: 3862111.1034         Z: 4107148.9857         [meters]
X: -2977429.0012        Y: 3877757.6239         Z: 4115433.3194         [meters]
X: -2990250.1591        Y: 3893363.9527         Z: 4123632.3733         [meters]
X: -3003046.0552        Y: 3908929.8361         Z: 4131747.2453         [meters]
X: -3015818.7649        Y: 3924455.1883         Z: 4139776.4856         [meters]
X: -3028565.6047        Y: 3939940.8013         Z: 4147721.1759         [meters]
X: -3041288.0255        Y: 3955384.342          Z: 4155582.4507         [meters]
X: -3053984.9075        Y: 3970787.2374         Z: 4163359.6845         [meters]
X: -3066657.2147        Y: 3986149.3501         Z: 4171052.2571         [meters]
X: -3079303.8802        Y: 4001469.3249         Z: 4178662.1554         [meters]
```

### ECF Velocity for the first 10 data points: 
```
0               [meters / second]
4374.658        [meters / second]
4359.652        [meters / second]
4344.573        [meters / second]
4329.653        [meters / second]
4314.646        [meters / second]
4299.593        [meters / second]
4284.602        [meters / second]
4269.696        [meters / second]
4254.646        [meters / second]
```

### Interpolated Velocities at time given:
```
Interpolated Velocity at Time (1532334000 [s]): 1389.53 [meters / second]
Interpolated Velocity at Time (1532335268 [s]): 3891.31 [meters / second]
```