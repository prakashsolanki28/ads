let list = new Linklist();

$('#insertFirst').on('click', function () {
	let data = prompt("Enter a Data -: ");
	if (!data) {
		return;
	}
	list.insertFirst(data);
	print();
});

$('#insertLast').on('click', function () {
	let data = prompt("Enter a Data -: ");
	if (!data) {
		return;
	}
	list.insertLast(data);
	print();
})

$('#insertAt').on('click', function () {
	let data = prompt("Enter a Data -: ");
	let index = prompt("Enter a Index -: ");
	if (!data || !index) {
		return;
	}
	list.insertAt(data, index);
	print();
})

$('#removeAt').on('click', function () {
	let index = prompt("Enter a Index -: ");
	if (!index) {
		return;
	}
	list.removeAt(index);
	print();
})

$('#clean').on('click', function () {
	list.clearList();
	print();
})
function print() {

	let data = list.get();
	$('#linklistdata li').remove();
	data.forEach((element, index) => {
		let next = element ? (element.next ? (element.next ? element.next.data ? "Address of " + element.next.data : "Null" : 'Null') : 'Null') : 'null';
		let show = index == 0 ? ("Head - { data:" + element.data + ", next: " + next + "}") : index == data.length - 1 ? ("Null - { data:" + element.data + ", next: null}") : "";

		if (element) {
			if (index == 0 || index == data.length - 1)
				$('#linklistdata').append("<li><div>" + element.data + "</div><div>" + next + "</div><span>" + show + "</span></li>");
			else
				$('#linklistdata').append("<li><div>" + element.data + "</div><div>" + next + "</div></li>");
		}
	});
}



$(document).ready(function () {
	// list.insertFirst(10);
	// list.insertFirst(20);
	// list.insertFirst(30);
	for (let index = 0; index < 20; index++) {
		list.insertFirst(Math.floor(Math.random()*4000));
	}
	print();
})
