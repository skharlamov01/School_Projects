/**
 * WEB222 – Assignment 05
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Sasha Kharlamov
 *      Date:       02/04/2022
 *
 * !! ALL PHOTOS WERE DOWNLOADED OFF PEXELS & FLICKR AS CC0/PUBLIC DOMAIN !!
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { products, categories } = window;

// For debugging, display all of our data in the console
console.log({ products, categories }, "Store Data");

//function to create each card dynamically
function createProductCard(product) {
  // Create a <div> to hold the card
  const card = document.createElement("div");
  // Add the .card class to the <div>
  card.classList.add("card");

  // Create a product image
  const productImage = document.createElement("img");
  productImage.src = product.imageUrl;
  card.appendChild(productImage);

  // create card text div
  const details = document.createElement("div");
  details.classList.add("card_details");

  // add all text into details div
  const title = document.createElement("h3");
  title.innerHTML = product.title;
  details.appendChild(title);

  const desc = document.createElement("p");
  desc.appendChild(document.createTextNode(product.description));
  details.appendChild(desc);

  let price = product.price / 100;
  price = Intl.NumberFormat("en-US", { style: "currency", currency: "CAD" }).format(price);
  const display_price = document.createElement("span");
  display_price.appendChild(document.createTextNode(price));
  details.appendChild(display_price);

  //appending all text into the card
  card.appendChild(details);
  // Return the card’s <div> element to the caller
  return card;
}

function displayProducts(category) {
  let valid_prods = products.filter((product) => {
    return product.discontinued === false && product.categories.includes(category.id);
  });
  document.querySelector("#selected-category").innerHTML = category.name;
  //deleting any previous card displays
  if (document.querySelector(".allCards") !== null) {
    const oldContainer = document.querySelector(".allCards");
    oldContainer.remove();
  }
  //creating card container to place all individual cards into
  let classContainer = document.createElement("div");
  classContainer.classList.add("allCards");
  //appending created container into main html
  let main = document.getElementById("main");
  main.appendChild(classContainer);
  //looping to create each valid card
  valid_prods.forEach((prod) => {
    const card = createProductCard(prod);
    card.onclick = function () {
      console.log({ prod });
    };
    classContainer.appendChild(card);
  });
}

window.onload = function () {
  let menu = document.querySelector("#menu");
  //dynamically creating buttons
  categories.forEach((cat) => {
    let buttonElem = document.createElement("button");
    let buttonText = document.createTextNode(cat.name);
    buttonElem.setAttribute("id", cat.id);
    buttonElem.appendChild(buttonText);
    menu.appendChild(buttonElem);
    buttonElem.onclick = function () {
      displayProducts(cat);
    };
  });
  displayProducts(categories[0]);
};
