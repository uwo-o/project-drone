import { NavigationContainer } from '@react-navigation/native';
import React, { useState } from 'react';

export default function Controller() {

    const navigation = useNavigation();

    return (<></>);
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#fff',
        alignItems: 'center',
        justifyContent: 'center',
    },
    textInput: {
        width: 200,
        height: 40,
        borderColor: 'gray',
        borderWidth: 1,
        textAlign: 'center',
    },
    btn: {
        width: 200,
        height: 40,
        backgroundColor: 'blue',
    },
});