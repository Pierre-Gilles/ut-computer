#Install GTest framework on mac

<br/>
**Installer le gestionnaire de paquets brew**
<br/>
**Installer wget et cmake**

```
brew install cmake
brew install wget
```








<br/>
**Telecharger Gtest dans un dossier lambda (Downloads par exemple)**

```
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip gtest-1.7.0.zip
cd gtest-1.7.0
```

<br/>
**Build Gtest dans un dossier lambda (Downloads par exemple)**

```
mkdir build
cd build
cmake -Dgtest_build_samples=ON -Dgtest_build_tests=ON /Users/marco/Downloads/gtest-1.7.0
make
make test
./sample1_unittest
```

<br/>
**"Install" gtest on the Mac**

Fausse installation : on met simplement le fichier .a dans un dossier facilement accessible depuis les projets

```
sudo mkdir /usr/local/Cellar/gtest
sudo cp gtest-1.7.0/build/libgtest.a /usr/local/Cellar/gtest/
sudo ln -snf /usr/local/Cellar/gtest/libgtest.a /usr/local/lib/libgtest.a
sudo cp -r gtest-1.7.0/include /usr/local/Cellar/gtest/
ln -snf ../Cellar/gtest/include/gtest /usr/local/include/gtest
```

<br/>
**Il suffit ensuite d'inclure les bons fichiers dans le CMakeList.txt du projet CLion et de linker la bonne librairie**

(Déjà fait, juste pour information)

```
include_directories(/usr/local/include)
target_link_libraries(test_inet /usr/local/lib/libgtest.a)
```