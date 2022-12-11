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

		let next = element ? element.next ? "Address of " + element.next.data : "Null" : "Null";
		let pre = element ? element.previous ? "Address of " + element.previous.data : "Null" : "Null";
		$('#linklistdata').append("<li><div>"+pre+"</div><div>" + element.data + "</div><div>"+next+"</div></li>")
	});
}


$(document).ready(function () {
	
	for (let index = 0; index < 3; index++) {
		list.insertFirst(Math.floor(Math.random() * 6000))
	}
	print();
});
