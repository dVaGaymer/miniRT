#!/bin/bash
echo Choose scene name
read SCENE_NAME
if [ $SCENE_NAME = "" ];
    then
        SCENE_NAME=unnamed_scene
        echo $SCENE_NAME could be overwritten
    fi
echo "#creation" $SCENE_NAME >> $SCENE_NAME.rt

VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
#R
until [[ $WIDTH =~ ^([0-1][0-8][0-9][0-9]|[0-1][0-9][0-2][0-0]|[0-9][0-9][0-9]|[0-9][0-9]|[1-9])$ ]]
do
    echo Window Width [1 - 1920]
    read WIDTH
    if [ $WIDTH == "" ]
    then
        WIDTH="1920"
    fi
done
until [[ $HEIGHT =~ ^([0-1][0-0][0-7][0-9]|[0-1][0-0][0-8][0-0]|[0-9][0-9][0-9]|[0-9][0-9]|[1-9])$ ]]
do
    echo Window Height [1 - 1080]
    read HEIGHT
    if [ $HEIGHT == "" ]
    then
        HEIGHT="1080"
    fi
done
echo R"\t"$WIDTH"\t"$HEIGHT >> $SCENE_NAME.rt 

#---------------------------------------------------------------------------------------------------------------

VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
#A
until [[ $VAR_0 =~ ^([0-0]|[1-1]|[0-0].[0-9]|[0-0].[0-9][0-9])$ ]]
do
    echo Ambient Light Brightness [0 - 1]
    read VAR_0
    if [ $VAR_0 == "" ]
    then
        VAR_0="0.2"
    fi
done
until [[ $VAR_1 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
do
    echo Ambient Light Color [0 - 255],[0 - 255],[0 - 255]
    read VAR_1
    if [ $VAR_1 == "" ]
    then
        VAR_1="255,255,255"
    fi
done
echo A"\t"$VAR_0"\t"$VAR_1 >> $SCENE_NAME.rt

VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
#C
until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
do
    echo Camera Position [ x ],[ y ],[ z ]
    read VAR_0
    if [ $VAR_0 == "" ]
    then
        VAR_0="-50,0,20"
    fi
done
until [[ $VAR_1 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
do
    echo Camera Orientation [ x ],[ y ],[ z ]
    read VAR_1
    if [ $VAR_1 == "" ]
    then
        VAR_1="0,0,0"
    fi
done
until [[ $VAR_2 =~ ^(((-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4])\.([0-9]|[0-9][0-9]))|(-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4]))$ ]]
do
    echo Camera Field of View [1 - 1024]
    read VAR_2
    if [ $VAR_2 == "" ]
    then
        VAR_2="70"
    fi
done
echo c"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2 >> $SCENE_NAME.rt

#-----MULTIPLE-----
NUM=""
#l
echo Number of Lights
read NUM
if [ $NUM == "" ]
then
    NUM="1"
fi
for ((i=0; i<$NUM; i++))
do
    VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
    until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Light Position [ x ],[ y ],[ z ]
        read VAR_0
        if [ $VAR_0 == "" ]
        then
            VAR_0="-40,0,30"
        fi
    done
    until [[ $VAR_1 =~ ^([0-0]|[1-1]|[0-0].[0-9]|[0-0].[0-9][0-9])$  ]]
    do
        echo Light Brightness [0 - 1]
        read VAR_1
        if [ $VAR_1 == "" ]
        then
            VAR_1="0.7"
        fi
    done
    until [[ $VAR_2 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
    do
        echo Light Color [0 - 255],[0 - 255],[0 - 255]
        read VAR_2
        if [ $VAR_2 == "" ]
        then
            VAR_2="255,255,255"
        fi
    done
    echo l"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2 >> $SCENE_NAME.rt
    echo NUM
done

#pl
NUM=""
echo Number of Planes
read NUM
if [ $NUM -e1 "" ]
then
    NUM="1"
fi
for ((i=0; i<$NUM; i++))
do
    VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
    until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Plane Position [ x ],[ y ],[ z ]
        read VAR_0
        if [ $VAR_0 == "" ]
        then
            VAR_0="0,0,0"
        fi
    done
    until [[ $VAR_1 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Plane Normal Vector [ x ],[ y ],[ z ]
        read VAR_1
        if [ $VAR_1 == "" ]
        then
            VAR_1="0,1.0,0"
        fi
    done
    until [[ $VAR_2 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
    do
        echo Plane Color [0 - 255],[0 - 255],[0 - 255]
        read VAR_2
        if [ $VAR_2 == "" ]
        then
            VAR_2="255,255,255"
        fi
    done
    echo pl"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2 >> $SCENE_NAME.rt
done

#sp
NUM=""
echo Number of Spheres
read NUM
if [ $NUM == "" ]
then
    NUM="1"
fi
for ((i=0; i<$NUM; i++))
do
    VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
    until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Sphere Center [ x ],[ y ],[ z ]
        read VAR_0
        if [ $VAR_0 == "" ]
        then
            VAR_0="0,0,20"
        fi
    done
    until [[ $VAR_1 =~ ^(((-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4])\.([0-9]|[0-9][0-9]))|(-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4]))$ ]]
    do
        echo Sphere Diameter [1 - 1024]
        read VAR_1
        if [ $VAR_1 == "" ]
        then
            VAR_1="20"
        fi
    done
    until [[ $VAR_2 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
    do
        echo Sphere Color [0 - 255],[0 - 255],[0 - 255]
        read VAR_2
        if [ $VAR_2 == "" ]
        then
            VAR_2="255,0,0"
        fi
    done
    echo sp"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2 >> $SCENE_NAME.rt
done

#sq
NUM=""
echo Number of Squares
read NUM
if [ $NUM == "" ]
then
    NUM="1"
fi
for ((i=0; i<$NUM; i++))
do
    VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
    until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Square Center [ x ],[ y ],[ z ]
        read VAR_0
        if [ $VAR_0 == "" ]
        then
            VAR_0="0,100,40"
        fi
    done
    until [[ $VAR_1 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Square Orientation [ x ],[ y ],[ z ]
        read VAR_1
        if [ $VAR_1 == "" ]
        then
            VAR_1="0,0,1.0"
        fi
    done
    until [[ $VAR_2 =~ ^(((-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4])\.([0-9]|[0-9][0-9]))|(-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4]))$ ]]
    do
        echo Square Side [1 - 1024]
        read VAR_2
        if [ $VAR_2 == "" ]
        then
            VAR_2="30"
        fi
    done
    until [[ $VAR_3 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
    do
        echo Square Color [0 - 255],[0 - 255],[0 - 255]
        read VAR_3
        if [ $VAR_3 == "" ]
        then
            VAR_3="42,42,0"
        fi
    done
    echo sq"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2"\t"$VAR_3 >> $SCENE_NAME.rt
done

#cy
NUM=""
echo Number of Cylinders
read NUM
if [$NUM == ""]
then
    NUM="1"
fi
for ((i=0; i<$NUM; i++))
do
    VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
    until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Cylinder Position [ x ],[ y ],[ z ]
        read VAR_0
        if [ $VAR_0 == "" ]
        then
            VAR_0="50.0,0.0,20.6"
        fi
    done
    until [[ $VAR_1 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Cylinder Orientation [ x ],[ y ],[ z ]
        read VAR_1
        if [ $VAR_1 == "" ]
        then
            VAR_1="0,0,0.1"
        fi
    done
    until [[ $VAR_2 =~ ^(((-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4])\.([0-9]|[0-9][0-9]))|(-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4]))$ ]]
    do
        echo Cylinder Diameter [1 - 1024]
        read VAR_2
        if [ $VAR_2 == "" ]
        then
            VAR_2="14.2"
        fi
    done
    until [[ $VAR_3 =~ ^(((-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4])\.([0-9]|[0-9][0-9]))|(-?[1-9]|-?[0-9][0-9]|-?[0-9][0-9][0-9]|-?[0-1][0-0][0-2][0-4]))$ ]]
    do
        echo Cylinder Height [1 - 1024]
        read VAR_3
        if [ $VAR_3 == "" ]
        then
            VAR_3="21.42"
        fi
    done
    until [[ $VAR_4 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
    do
        echo Cylinder Color [0 - 255],[0 - 255],[0 - 255]
        read VAR_4
        if [ $VAR_4 == "" ]
        then
            VAR_4="10,0,255"
        fi
    done
    echo cy"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2"\t"$VAR_3"\t"$VAR_4 >> $SCENE_NAME.rt
done

#tr
NUM=""
echo Number of Triangles
read NUM
if [ $NUM == "" ]
then
    NUM="1"
fi
for ((i=0; i<$NUM; i++))
do
    VAR_0="" && VAR_1="" && VAR_2="" && VAR_3="" && VAR_4=""
    until [[ $VAR_0 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Triangle First Point [ x ],[ y ],[ z ]
        read VAR_0
        if [ $VAR_0 == "" ]
        then
            VAR_0="10,20,10"
        fi
    until [[ $VAR_1 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Triangle Second Point [ x ],[ y ],[ z ]
        read VAR_1
        if [ $VAR_1 == "" ]
        then
            VAR_1="10,10,20"
        fi
    done
    until [[ $VAR_2 =~ ^(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+),(-?[0-9]+\.[0-9]+|-?[0-9]+)$ ]]
    do
        echo Triangle Third Point [ x ],[ y ],[ z ]
        read VAR_2
        if [ $VAR_2 == "" ]
        then
            VAR_2="20,10,10"
        fi
    done
    until [[ $VAR_3 =~ ^([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5]),([0-9]|[0-9][0-9]|[0-2][0-4][0-9]|[0-2][0-5][0-5])$ ]]
    do
        echo Triangle Color [0 - 255],[0 - 255],[0 - 255]
        read VAR_3
        if [ $VAR_3 == "" ]
        then
            VAR_3="0,0,255"
        fi
    done
    echo tr"\t"$VAR_0"\t"$VAR_1"\t"$VAR_2"\t"$VAR_3 >> $SCENE_NAME.rt
done
