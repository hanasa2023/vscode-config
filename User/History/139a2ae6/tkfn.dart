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
  child: Column(),
);

final List<Widget> items = <Widget>[
  _buildCard("happy-birthday", "jpg"),
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
