import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, View, TouchableOpacity, TextInput } from 'react-native';
import React, { useState } from 'react';

const ipFormat = (ip) => {
  if (!ip) {
    return false;
  }

  const ipArr = ip.split('.');

  if (ipArr.length !== 4) {
    return false;
  }

  for (let i = 0; i < ipArr.length; i++) {
    if (ipArr[i] < 0 || ipArr[i] > 255) {
      return false;
    }
  }

  return true;
}
const onConnect = (ip) => {

  if (!ip) {
    alert('Please insert IP');
    return;
  }

  if (!ipFormat(ip)) {
    alert('Invalid IP');
    return;
  }

  alert('Connecting to ' + ip);
}

export default function App() {
  const [value, onChangeText] = useState('');

  return (
    <View style={styles.container}>
      <Text
        style={{fontSize: 20, marginBottom: 10}}
      >Insert Drone IP</Text>
      <TextInput
        style={styles.textInput}
        onChangeText={text => onChangeText(text)}
        value={value}
        placeholder='192.168.1.1'
        keyboardType='numeric'
      />
      <View style={{marginTop: 10}}>
        <TouchableOpacity
          title="Connect"
          style={styles.btn}
          onPress={() => onConnect(value)}
        >
          <Text style={{color: 'white', textAlign: 'center', lineHeight: 40}}>Connect</Text>
        </TouchableOpacity>
      </View>
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  textInput: {
    height: 40,
    width: 200,
    borderColor: 'gray',
    borderWidth: 1,
    borderRadius: 5,
    padding: 10,
  },
  btn: {
    marginTop: 10,
    textColor: 'white',
    width: 200,
    height: 40,
    borderRadius: 5,
    backgroundColor: 'black',
  }
});
