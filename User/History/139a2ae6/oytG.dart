import 'package:flutter/material.dart';

void main() => runApp(const HappyBirthdayApp());

class HappyBirthdayApp extends StatelessWidget {
  const HappyBirthdayApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Material App",
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: Scaffold(
        appBar: AppBar(
          title: const Text("生日快乐！！！！！"),
        ),
        body: Container(
          padding: const EdgeInsets.all(16.0),
          child: listviews,
        ),
      ),
    );
  }
}

Widget listviews = const ListViews();

Card _buildCard(String image, String type) => Card(
      child: Column(
        children: [
          Image.asset(
            'images/$image.$type',
          ),
          Center(
            child: Text(image),
          ),
        ],
      ),
    );

Widget what_to_say = const Card(
  child: Column(
    children: [
      Text(
        "总之就是祝我最最最可爱的母亲生日快乐！！！！！！",
        textAlign: TextAlign.center,
        style: TextStyle(
          fontSize: 20.0,
          fontWeight: FontWeight.bold,
          decoration: TextDecoration.underline,
          decorationStyle: TextDecorationStyle.solid,
        ),
      ),
      Text(
        "PS:没学多少知识就上手，而且准备考试，所以没花多少时间制作这份礼物，望见凉。",
      ),
    ],
  ),
);

final List<Widget> items = <Widget>[
  _buildCard("happy-birthday", "jpg"),
  what_to_say,
  _buildCard("2018-2-23", "jpeg"),
  _buildCard("2018-2-28", "jpeg"),
  _buildCard("2018-2-28", "jpg"),
  _buildCard("2018-3-17", "jpeg"),
];

class ListViews extends StatefulWidget {
  const ListViews({super.key});

  @override
  State<StatefulWidget> createState() => _ListViewsState();
}

class _ListViewsState extends State<ListViews> {
  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      scrollDirection: Axis.vertical,
      itemCount: items.length,
      itemBuilder: ((context, index) => items[index]),
    );
  }
}
