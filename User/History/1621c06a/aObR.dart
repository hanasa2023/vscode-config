// import 'dart:html';

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.white,
        body: Column(
          children: [
            titleSection,
            buttonSection,
            form,
            smallwidgets,
            // animationSample,
            animated_container,
          ],
        ),
      ),
    );
  }
}

//标题栏
Widget titleSection = Container(
  padding: const EdgeInsets.all(32),
  child: Row(
    children: [
      Expanded(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
/*2*/
            Container(
              padding: const EdgeInsets.only(bottom: 8),
              child: const Text(
                'Oeschinen Lake Campground',
                style: TextStyle(
                  fontWeight: FontWeight.bold,
                ),
              ),
            ),
            Text(
              'Kandersteg, Switzerland',
              style: TextStyle(
                color: Colors.grey[500],
              ),
            ),
          ],
        ),
      ),
/*3*/
      Icon(
        Icons.star,
        color: Colors.red[500],
      ),
      const Text('41'),
    ],
  ),
);

///按钮组
Column _buildButton(Color color, IconData icon, String label) {
  return Column(
    mainAxisSize: MainAxisSize.min,
    mainAxisAlignment: MainAxisAlignment.center,
    children: [
      Icon(
        icon,
        color: color,
      ),
      Container(
        margin: const EdgeInsets.only(top: 8.0),
        child: Text(
          label,
          style: TextStyle(
            fontSize: 12.0,
            fontWeight: FontWeight.w400,
            color: color,
          ),
        ),
      ),
    ],
  );
}

Color color = Colors.blue;

Widget buttonSection = Row(
  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
  children: [
    _buildButton(color, Icons.call, "CALL"),
    _buildButton(color, Icons.near_me, "ROUTE"),
    _buildButton(color, Icons.share, "SHARE"),
  ],
);

/// Form组件
class MyForm extends StatefulWidget {
  const MyForm({super.key});

  @override
  MyFormState createState() => MyFormState();
}

class MyFormState extends State<MyForm> {
  final _formkey = GlobalKey<FormState>();
  var name = '';

  @override
  Widget build(BuildContext context) {
    return Form(
      key: _formkey,
      child: Container(
        padding: const EdgeInsets.all(32.0),
        child: Column(
          children: [
            TextFormField(
              onSaved: (v) => name = v!,
              validator: (v) {
                if (v!.isEmpty) {
                  return "用户名不能为空";
                }
                return null;
              },
              decoration: const InputDecoration(
                border: OutlineInputBorder(),
                labelText: 'Please enter u nickname',
              ),
            ),
            Text(name),
            ElevatedButton(
              onPressed: () {
                if (_formkey.currentState!.validate()) {
                  _formkey.currentState!.save();
                }
              },
              child: const Text('Submit'),
            ),
          ],
        ),
      ),
    );
  }
}

Widget form = const MyForm();

///Switch、Checkbox、Radio组件

//switch
Widget myswitch = MySwitch();

class MySwitch extends StatefulWidget {
  const MySwitch({super.key});

  @override
  State<MySwitch> createState() => _MySwitchState();
}

class _MySwitchState extends State<MySwitch> {
  var _value = false;

  @override
  Widget build(BuildContext context) {
    return Switch(
      value: _value,
      activeTrackColor: Colors.blue,
      activeColor: Colors.blue[400],
      onChanged: (v) {
        setState(() {
          _value = v;
        });
      },
    );
  }
}

//checkbox
Widget mycheckbox = MyCheckBox();

class MyCheckBox extends StatefulWidget {
  const MyCheckBox({super.key});

  @override
  State<MyCheckBox> createState() => _MyCheckBoxState();
}

class _MyCheckBoxState extends State<MyCheckBox> {
  var _value = false;

  @override
  Widget build(BuildContext context) {
    return Checkbox(
      value: _value,
      activeColor: Colors.amber,
      onChanged: (v) {
        setState(() {
          _value = v!;
        });
      },
    );
  }
}

//radio
Widget myradio = MyRadio();

class MyRadio extends StatefulWidget {
  const MyRadio({super.key});

  @override
  State<MyRadio> createState() => _MyRaidoState();
}

enum Sex { boy, girl }

class _MyRaidoState extends State<MyRadio> {
  Sex _radioValue = Sex.boy;

  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        Radio(
          value: Sex.boy,
          groupValue: _radioValue,
          onChanged: (v) {
            setState(() {
              _radioValue = v!;
            });
          },
        ),
        Radio(
          value: Sex.girl,
          groupValue: _radioValue,
          onChanged: (v) {
            setState(() {
              _radioValue = v!;
            });
          },
        ),
      ],
    );
  }
}

Widget smallwidgets = Row(
  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
  children: [
    myswitch,
    mycheckbox,
    myradio,
  ],
);

///Animation

Widget animationSample = AnimationSample();

class AnimationSample extends StatefulWidget {
  const AnimationSample({super.key});

  @override
  State<AnimationSample> createState() => _AnimationSampleState();
}

class _AnimationSampleState extends State<AnimationSample>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;
  late Animation<Color> tweenAnimation;

  @override
  void initState() {
    super.initState();

    _controller = AnimationController(
      vsync: this,
      duration: new Duration(seconds: 1),
    );
    _controller.addListener(() {
      setState(() {});
    });

    Tween<Color> tween = Tween<Color>(
      begin: Colors.red,
      end: Colors.blue,
    );
    tweenAnimation = tween.animate(_controller);

    startAnimation();
  }

  void startAnimation() {
    _controller.forward();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        height: _controller.value * 100,
        color: tweenAnimation.value,
      ),
    );
  }
}

///AnimatedContainer

Widget animated_container = ACSample();

class ACSample extends StatefulWidget {
  const ACSample({super.key});

  @override
  State<ACSample> createState() => _ACSampleState();
}

class _ACSampleState extends State<ACSample> {
  bool select = false;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onDoubleTap: () => setState(() {
        select = !select;
      });,
      child: AnimatedContainer(
        height: select ? 100 : 200,
        width: select ? 100 : 200,
        color: select ? Colors.blue : Colors.red,
        duration: const Duration(seconds: 2),
        child: const Icon(Icons.abc),
      ),
    );
  }
}
